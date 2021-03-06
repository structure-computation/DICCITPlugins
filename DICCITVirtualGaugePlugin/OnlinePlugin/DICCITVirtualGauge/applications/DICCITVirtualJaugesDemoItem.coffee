class DICCITVirtualJaugesDemoItem extends TreeItem
    constructor: (name = 'Image correlation')->
        super()
                
        @_name.set name
        
        @add_attr
            edited_by : 'SC'
            stamp: "img/virtual_jauges.png"
            txt: "Jauge Virtuelle"
            demo_app : "DICCITVirtualJaugesDemoItem"
            directory : "DICCITVirtualJauges"
            video_link : '<iframe width="853" height="480" src="https://www.youtube.com/embed/RLtYI3v2BgQ?rel=0" frameborder="0" allowfullscreen></iframe>'
            tutorial_link : undefined
            publication_link : undefined

    associated_application: ()->
        apps = new Lst
        apps.push new TreeAppApplication_DICCITVirtualGauge
        return apps
    
    run_demo : (app_data)->
        app = new TreeAppApplication
        a = app.add_item_depending_selected_tree app_data, DICCITVirtualGaugeItem_v1
        
            
    onclick_function: ()->
        window.location = "softpage.html#" +  @demo_app
                