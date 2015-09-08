#include <Soca/Com/SodaClient.h>
#include <Soca/Model/TypedArray.h>
#include <QtCore/QFile>
#include <QtCore/QTemporaryFile>
#include <QtCore/QDataStream>

#include "../../../sources/commandes_generales.h"
#include "mesh/interpolation.h"
#include "mesh/write_mesh_vtk.h"

#include "FieldCompareUpdater.h"


bool FieldCompareUpdater::run( MP mp ) {
    
    MP ch = mp[ "_children" ];
    Vec< Vec<TM> > Mesh_Vector_input;  Mesh_Vector_input.resize(2);
    Vec<FieldSet> Field_Vector_input; Field_Vector_input.resize(2);
    TM GaugeMesh;
    
    // chargement des mailages au format LMTpp
    for( int ii = 0; ii < ch.size(); ++ii ){
        qDebug() << "ii = " << ii;
        MP c = ch[ ii ];
        qDebug() << c.type();
        if ( c.type() == "FieldSetItem" ){
            FieldSet fs_input(c); 
            Field_Vector_input[ii] = (fs_input);
            Mesh_Vector_input[ii] = load_FieldSetItem_into_LMTpp_Mesh(fs_input);
//             std::cout << "ok2" << std::endl;
        }
    }
    
    

    //construction du maillage et du champs de référence
    Mesh_vecs maillage; maillage.load(ch[0]["visualization.color_by.lst[0].data._data[0].field._mesh"]);
    MP maillage_transfert = maillage.save();
    GaugeMesh = load_MeshMP_into_2DLMTpp_Mesh(maillage_transfert);
    
    qDebug() << "ok0";
    FieldSet field_transfert = Field_Vector_input[0] - Field_Vector_input[0]; 
    qDebug() << "ok1";
    field_transfert.save(mp["_output[0]._children[0]"]);
    qDebug() << mp["_output"];
    qDebug() << "ok2";
    MP output_field_set = mp["_output[0]._children[0]"];
    qDebug() << output_field_set;

    //interpolation du champs 1 sur le maillage de référence 0
    Vec<Vec<double> > dep_tmp; dep_tmp.resize(TM::dim);
    GetEpsInVecs ge;
    for (int no = 0; no < GaugeMesh.node_list.size(); no++){
        GaugeMesh.node_list[ no ].dep = interpolation( Mesh_Vector_input[1][0], dep_DM(), GaugeMesh.node_list[ no ].pos );
        for (int d = 0; d < TM::dim; d++)
            dep_tmp[d] << GaugeMesh.node_list[ no ].dep[d];
    }
    qDebug() << "ok4";
    
    //construction du champ output 
//     MP data_field = output_field_set["visualization.color_by.lst"];
//     data_field.clear();
    QVector<MP> displacements;// = make_field( output_field_set, GaugeMesh.dim, "Displacement" );
    displacements << make_field( output_field_set, "compare" );
    
    qDebug() << "ok4";
    // disp field
    MP mesh = ch[0]["visualization.color_by.lst[0].data._data[0].field._mesh"];
//     for( int d = 0; d < GaugeMesh.dim; ++d ) {
        // data
        QVector<int> s; s << GaugeMesh.node_list.size();
        TypedArray<double> *data = new TypedArray<double>( s );

        for( int i = 0; i < GaugeMesh.node_list.size(); ++i )
            data->operator[]( i ) = GaugeMesh.node_list[ i ].dep[ 0 ];

        // NodalField
        add_field_in_Interpolated( displacements[ 0 ], mesh, data, 0 );
//     }
    
    mp.flush();

}



