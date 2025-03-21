let num1 = 0;
let num2 = 0;
let operacion;
let hayOperacion = false;
let tamano = 10;

let reinicio = () => {
    num1 = 0;
    num2 = 0;
    operacion = '';
    hayOperacion = false;
    document.getElementById('pantalla').textContent = '0';
};

let agregarNumero = (numero) => {
    let pantalla = document.getElementById('pantalla').textContent;
    if (pantalla.length == tamano) {
        return;
    }
    if (pantalla == '0') {
        document.getElementById('pantalla').textContent = '';
        document.getElementById('pantalla').textContent = numero;
    } else {
        document.getElementById('pantalla').textContent = pantalla + numero;
    }
};

let aperador = (operador) => {
    if (!hayOperacion) {
        num1 = document.getElementById('pantalla').textContent;
        operacion = operador;
        document.getElementById('pantalla').textContent = '';
        hayOperacion = true;
    }
};

let operaciones = () => {
    let resultado = 0;
    switch (operacion) {
        case '+': {
            resultado = parseInt(num1) + parseInt(num2);
            break;
        }
        case '-': {
            resultado = parseInt(num1) - parseInt(num2);
            break;
        }
        case '*': {
            resultado = parseInt(num1) * parseInt(num2);
            break;
        }
        case '/': {
            resultado = parseInt(num1) / parseInt(num2);
            break;
        }
    }
    return resultado;
};

let limpiarDatos = () => {
    reinicio();
};

let limpiar = () => {
    document.getElementById('pantalla').textContent = '';
    if (hayOperacion) {
        num2 = '';
    } else {
        num1 = '';
    }
};

let calcular= () => {
}