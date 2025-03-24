let principal=()=>{
    caveza();
    menu();
    
}

let caveza=()=>{
    let cabesero=document.getElementById("cabesero"); 
    cabesero.innerHTML="<h1>Portafolio Personal</h1>";
};

let menu=()=>{
    let menu=document.getElementById("menu");
    menu.innerHTML=`
                <li class="boton"><a href="indes.html">inicio</a></li>
                <li class="boton"><a href="pages/about_me.html">sobre mi</a></li>
                <li class="boton"><a href="pages/projects.html">proyectos</a></li>
            `;
};
