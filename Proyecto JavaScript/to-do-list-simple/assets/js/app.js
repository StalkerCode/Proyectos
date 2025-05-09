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
    const checkboxId = `iconcheckbox-${tareaObj.getTarea().replace(/\s+/g, '-')}`;
    const iconName = tareaObj.getEstado() ? 'checkbox-outline' : 'tablet-landscape-outline';
    return `
    <div class="todo-list">
        <div class="todo-checkbox" id="${checkboxId}"><ion-icon name="${iconName}"></ion-icon></div>
        <span>${tareaObj.getTarea()}</span>
        <button class="delete-btn" onclick="eliminarTarea('${tareaObj.getTarea()}')"><ion-icon name="trash-outline"></ion-icon></button>
        <button class="done-btn" onclick="marcarTarea('${tareaObj.getTarea()}')"><ion-icon name="checkmark-done-circle-outline"></ion-icon></button>
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
