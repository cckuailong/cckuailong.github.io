(function($) {
    var upperLimit = 100;

    // Our scroll link element
    var scrollElem = $('#totop');

    // Scroll to top speed
    var scrollSpeed = 1600;
    //scrollElem.hide();
    $(window).scroll(function () {
        var scrollTop = $(document).scrollTop();
        if ( scrollTop > upperLimit ) {
            $(scrollElem).stop().fadeTo(300, 1); 
        }else{
            $(scrollElem).stop().fadeTo(300, 0); 
        }
    });
    $(scrollElem).click(function(){
        $('html, body').animate({scrollTop:0}, scrollSpeed); return false;
    });
})(jQuery);