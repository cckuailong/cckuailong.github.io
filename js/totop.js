//$('#totop').hide();
	$(window).scroll(function(){
		if($(document).scrollTop()>100){
			$('#totop').fadeIn();
		}else{
			$('#totop').fadeOut();
		}
	});	
	
	$('#totop').click(function(){
		var juantop=$(document).scrollTop();
		$('html,body').animate({scrollTop:0},600);
		return false;
	});