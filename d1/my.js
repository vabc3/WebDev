$(document).ready(function() {
    $('#p1').hide();
    
    $(function () {
        $(window).scroll(function () {
            if ($(this).scrollTop() > 100) {
                $('#p1').fadeIn();
            } else {
                $('#p1').fadeOut();
            }
        });

        // scroll body to 0px on click
        $('#p1').click(function () {
            $('body,html').animate({
                scrollTop: 0
            }, 400);
            return false;
        });
    });
});
