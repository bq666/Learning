$(document).ready(() => {
 
  $('.login-button').on('click', () => {
    $('.login-form').toggle();
  });
  
  $('.menu-button').on('mouseenter', () => {
    $('.nav-menu').show();
    $('.menu-button').addClass('button-active');
    $('.nav-menu').removeClass('hide');
    
    $('.menu-button').animate({
      fontSize: '24px'
    }, 200)
  })
  
  $('.nav-menu').on('mouseleave', () => {
    $('.menu-button').removeClass('button-active')
    
    $('.menu-button').animate({
      fontSize: '18px'
    }, 200)
  })
  
}); 
