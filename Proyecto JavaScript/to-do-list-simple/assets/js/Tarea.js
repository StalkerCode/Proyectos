class Tarea {
	constructor(tarea) {
		this.tarea = tarea;
		this.estado = false;
	}
	// gets and sets
	getTarea() { return this.tarea; }
	setTarea(tarea) { this.tarea = tarea; }
	getEstado() { return this.estado; }
	setEstado(estado) { this.estado = estado; }
	// toString
	toString() {
		return `Tarea: ${this.tarea} - Estado: ${this.estado}`;
	}
}	