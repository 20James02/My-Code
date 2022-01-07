window.onclick = function(event1) {
  var b = document.getElementById('id02');
  var a = document.getElementById('id01');
  if (event1.target == a) {
    a.style.display = "none";
  }
  if (event1.target == b) {
    b.style.display = "none";
  }
}

$(document).ready(function(){
  $("#button1").click(function(){
    $("#id01").fadeIn("slow");
  });
});


$(document).ready(function(){
  $("#button2").click(function(){
    $("#id02").fadeIn("slow");
  });
});






