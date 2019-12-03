import random

def save(filename, content):
    f = open(filename, "w")

    f.write(content);

    f.close()

def gerarInstancia(max_clientes, max_depositos, max_val, max_preco):
    numClientes = random.randint(5, max_clientes)
    numDepositos = random.randint(5, max_depositos)

    totalDemanda = random.randint(int(0.1 * max_val), max_val)
    totalOferta = totalDemanda

    u = int(totalDemanda / numClientes)

    tempDemanda = totalDemanda
    tempOferta = totalOferta

    demanda = []
    oferta =  []
    custos = []

    for i in range(numClientes - 1):
        v = u - random.randint(int(0.1 * u), int(u * 0.6))

        demanda.append(v)

        tempDemanda = tempDemanda - v
    
    demanda.append(tempDemanda)

    u = int(totalOferta / numDepositos)

    for i in range(numDepositos - 1):
        v = u - random.randint(int(0.1 * u), int(u * 0.6))

        oferta.append(v)

        tempOferta = tempOferta - v
    
    oferta.append(tempOferta)

    for i in range(numClientes):
        for j in range(numDepositos):
            custos.append(random.randint(0.1 * max_preco, max_preco))

    return (numClientes, numDepositos, demanda, oferta, custos)

def formatarInstancia(instancia):
    output = ""
    output += str(instancia[0]) + " " + str(instancia[1]) + "\n"
    
    for i in instancia[2]:
        output += str(i) + " "
    output += "\n"

    for i in instancia[3]:
        output += str(i) + " "
    output += "\n"
    
    for i in range(instancia[0]):
        for j in range(instancia[1]):
            output += str(instancia[4][i * instancia[1] + j]) + " "
        output += "\n"
    
    return output

def gerarInstancias(numInstancias):
    for i in range(numInstancias):
        instancia = gerarInstancia(20, 20, 5000, 500)
        content = formatarInstancia(instancia)
        save("instancia_" + str(i) + ".txt", content)


gerarInstancias(10)
