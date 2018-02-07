// Our scroll link element

var backButton = $('#totop');

function backToTop() {  
    $('html,body').animate({  
        scrollTop: 0  
    }, 800);  
}  

backButton.on('click', backToTop);  
  
$(window).on('scroll', function () {/*当滚动条的垂直位置大于浏览器所能看到的页面的那部分的高度时，回到顶部按钮就显示 */  
    if ($(window).scrollTop() > $(window).height())  
        backButton.fadeIn();  
    else  
        backButton.fadeOut();  
});  
$(window).trigger('scroll');/*触发滚动事件，避免刷新的时候显示回到顶部按钮*/