let tareas = [];
function agregarTarea(){
	let tarea = document.getElementById("text").value
	if(!estaVacio(tarea)){
		tareas.push(new Tarea(tarea));
	}
	for (let t of tareas){
		console.log(t.toString());
		
	}
	
}

function estaVacio(texto){
	if (texto == null) 
		return true;
	if (texto == undefined) 
		return true;
	texto=texto.trim();
	if (texto == "") 
		return true;
	return false;
}