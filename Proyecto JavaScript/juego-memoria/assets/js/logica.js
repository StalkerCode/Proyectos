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
const arrayAleatorio = generarArrayAleatorio();

function cartas() {

    let tarjetas = "";
    for (const numero of arrayAleatorio) {
        tarjetas += `<div class="carta" data-id="${numero}"></div>`;
    }
    document.getElementById("tablero").innerHTML = tarjetas;
}
