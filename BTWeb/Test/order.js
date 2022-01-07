const size = document.querySelectorAll(".sec-sz");
size.forEach((select) => select.addEventListener("click", function (event) {
    size.forEach((el) => el.classList.remove("select"));
    event.target.classList.add("select");
    })
);

var i = 0;
    function add() {
        if( i == 6){
            return;
        }
        i++;
        document.getElementById('numValue').value = i;
    }
    function sub() {
        if( i == 1){
            return;
        }
        i--;
        document.getElementById('numValue').value = i;
    }

    
function openOrder() {
    document.getElementById("id03").style.display = "block";
}