module analyze_data
export media, varianza, desviacion_estandar

# funcion para calcular la media de un vector de numeros
function media(datos)
    return sum(datos) / length(datos)
end

# funcion para calcular la varianza de un vector de numeros
function varianza(datos)
    n = length(datos)
    media_datos = media(datos)
    varianza = sum((x - media_datos)^2 for x in datos) / (n)
end

# funcion para calcular la desviacion estandar de un vector de numeros
function desviacion_estandar(datos)
    varianza_datos = varianza(datos)
    return sqrt(varianza_datos)

end

end