let tareas = [];

function agregarTarea() {
    let tareaTexto = document.getElementById("text").value;
    if (!estaVacio(tareaTexto) && !yaExisteTarea(tareaTexto)) {
        let nuevaTarea = new Tarea(tareaTexto);
        tareas.push(nuevaTarea);
        document.getElementById("todo-list-container").innerHTML += crearTarea(nuevaTarea);
    }
	document.getElementById("text").value = '';
}

function crearTarea(tareaObj) {
    const checked = tareaObj.getEstado() ? 'checked' : '';
    return `
    <div class="todo-list">
        <input type="checkbox" class="todo-checkbox" ${checked} disabled>
        <span>${tareaObj.getTarea()}</span>
        <button class="delete-btn" onclick="eliminarTarea('${tareaObj.getTarea()}')">X</button>
        <button class="done-btn" onclick="marcarTarea('${tareaObj.getTarea()}')">Done</button>
    </div>
    `;
}

function estaVacio(texto) {
    return !texto || texto.trim() === '';
}

function yaExisteTarea(tareaX) {
    return tareas.some(t => t.getTarea() === tareaX);
}

function actualizarTareas() {
    const tareasDOM = document.getElementById("todo-list-container");
    tareasDOM.innerHTML = '';
    tareas.forEach(tarea => {
        tareasDOM.innerHTML += crearTarea(tarea);
    });
}

function marcarTarea(tareaTexto) {
    let tareaEncontrada = tareas.find(t => t.getTarea() === tareaTexto);
    if (tareaEncontrada && !tareaEncontrada.getEstado()) {
        tareaEncontrada.setEstado(true);
        actualizarTareas();
    }
}

function eliminarTarea(tareaNombre) {
    let tarea = tareas.find(t => t.getTarea() === tareaNombre);
    if (tarea) {
        tareas = tareas.filter(t => t.getTarea() !== tareaNombre); // Elimina la tarea del array
        actualizarTareas();
    }
}
