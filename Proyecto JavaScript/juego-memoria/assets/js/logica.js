function generarArrayAleatorio() {
    // Crear un array con los números del 1 al 8, cada uno repetido dos veces
    let numeros = [];
    for (let i = 1; i <= 8; i++) {
        numeros.push(i, i);
    }

    // Función para desordenar el array de manera aleatoria (algoritmo de Fisher-Yates)
    function desordenarArray(array) {
        for (let i = array.length - 1; i > 0; i--) {
            const j = Math.floor(Math.random() * (i + 1));
            [array[i], array[j]] = [array[j], array[i]];
        }
    }

    // Desordenar el array
    desordenarArray(numeros);

    return numeros;
}
let arrayAleatorio = generarArrayAleatorio();

let primeraCarta = null;
let segundaCarta = null;
let paresDescubiertas = 0;
let parejasDescubiertas = [];

function cartas() {
    // Generar el HTML para las tarjetas
    let tarjetas = "";
    for (const numero of arrayAleatorio) {
        tarjetas += `<div class="carta" data-id="${numero}" onclick="voltear(this)"></div>`;
    }
    document.getElementById("tablero").innerHTML = tarjetas;

}


function voltear(carta) {
    // Verificar si la carta ya ha sido descubierta
    if (parejasDescubiertas.includes(carta.dataset.id)) {
        return;
    }

    // Verificar si la carta es la misma que la primera carta seleccionada
    if (primeraCarta != null && primeraCarta === carta) {
        return;
    }

    if (primeraCarta == null) {
        primeraCarta = carta;
        primeraCarta.classList.add('mostar');
    } else if (segundaCarta == null) {
        segundaCarta = carta;
        segundaCarta.classList.add('mostar');
        verificarCartas();
    }
}

function verificarCartas() {
    if (primeraCarta.dataset.id === segundaCarta.dataset.id) {
        // Agregar el ID a la lista de parejas descubiertas
        parejasDescubiertas.push(primeraCarta.dataset.id);
        paresDescubiertas += 1;
        primeraCarta = null;
        segundaCarta = null;
        reinicioJuego();
    } else {
        setTimeout(() => {
            primeraCarta.classList.remove('mostar');
            segundaCarta.classList.remove('mostar');
            primeraCarta = null;
            segundaCarta = null;
        }, 500);


    }
}

function reinicioJuego() {
    if (paresDescubiertas === 8) {
        // Mostrar un mensaje de reinicio (opcional)
        alert("¡Felicidades! Has completado el juego. Reiniciando...");

        // Reiniciar variables
        primeraCarta = null;
        segundaCarta = null;
        paresDescubiertas = 0;
        parejasDescubiertas = []; // Reiniciar la lista de parejas descubiertas

        // Volver a generar el array aleatorio
        arrayAleatorio = generarArrayAleatorio();

        // Actualizar el HTML del tablero
        cartas();
    }
}