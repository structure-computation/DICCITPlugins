#
class FieldCompareItem extends TreeItem_Computable
    constructor: ( name = "FieldCompare" ) ->
        super()
        
        @_name.set name
        @_viewable.set false
        
        @add_attr
            field_1 :
                time_step : 0
            field_2 :
                time_step : 0
        
        test = new TreeItem
        test._name.set "output"
        test.add_child new FieldSetItem
        @add_output test
        
       
        
    display_suppl_context_actions: ( context_action )  ->
        
    accept_child: ( ch ) ->
        ch instanceof FieldSetItem
        
#     z_index: ->
#         @_mesh.z_index()
        
    disp_only_in_model_editor: ->
#         @mesh

    