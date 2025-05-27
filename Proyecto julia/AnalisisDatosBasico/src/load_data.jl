module load_data

export cargar_hoja

# Cargar los datos de las flores desde el archivo CSV
function cargar_hoja()
    path = "src/data/iris_data.csv"
    datos = []
    open(path, "r") do archivo
        for linea in eachline(archivo)
            # Omitir líneas vacías o que solo tienen espacios
            if isempty(strip(linea))
                continue
            end
            subfila = split(linea, ",")
            nueva_fila = Any[parse(Float64, dato) for dato in subfila[1:end-1]]
            push!(nueva_fila, subfila[end])
            push!(datos, nueva_fila)
        end
    end
    return datos
end

end
