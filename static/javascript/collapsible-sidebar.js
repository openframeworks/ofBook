// Sidebar menu - trigger CSS transitions and swap button open/close buttons

$("#menu-close").hide();
$(document.body).addClass("sidebar-closed");

$("#menu-open").click(function () {
    $(document.body).addClass("sidebar-open").removeClass("sidebar-closed");
    $("#menu-close").show();
    $("#menu-open").hide();
});

$("#menu-close").click(function () {
    $(document.body).addClass("sidebar-closed").removeClass("sidebar-open");
    $("#menu-open").show();
    $("#menu-close").hide();
});