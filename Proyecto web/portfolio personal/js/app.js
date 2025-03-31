const principal = () => {
    cabecera();
    crearMenu();
    pieDePagina();
};

const cabecera = () => {
    const cabeceraElement = document.getElementById("cabesero");
    cabeceraElement.innerHTML = "<h1>Portafolio Personal</h1>";
};

const crearMenu = () => {
    const menuElement = document.getElementById("menu");
    menuElement.innerHTML = `
        <li class="boton"><a href="/index.html">Inicio</a></li>
        <li class="boton"><a href="/pages/about_me.html">Sobre mí</a></li>
        <li class="boton"><a href="/pages/projects.html">Proyectos</a></li>
    `;
};

const pieDePagina = () => {
    const pieElement = document.getElementById("pie");
    pieElement.textContent = "© 2025 ShadowCodeStalker. Todos los derechos reservados.";
};
