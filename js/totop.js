// Our scroll link element

var backButton = $('#totop');

function backToTop() {  
    $('html,body').animate({  
        scrollTop: 0  
    }, 800);  
}  

backButton.on('click', backToTop);  

$(window).on('scroll', function () {
    if ($(window).scrollTop() > $(window).height())  
        backButton.fadeIn();  
    else  
        backButton.fadeOut();  
});  
$(window).trigger('scroll');