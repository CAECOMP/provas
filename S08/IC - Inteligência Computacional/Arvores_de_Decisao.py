dados = [
    ['Sim','Alta','Quente', 'Ensolarado', 'Não foi jogar tênis'],
    ['Sim','Alta','Quente', 'Ensolarado', 'Não foi jogar tênis'],
    ['Não','Alta','Quente', 'Nublado', 'Foi jogar tênis'],
    ['Não','Alta','Média', 'Chuva', 'Foi jogar tênis'],
    ['Não','Normal','Fria', 'Chuva', 'Foi jogar tênis'],
    ['Sim','Normal','Fria', 'Chuva', 'Não foi jogar tênis'],
    ['Sim','Normal','Fria', 'Nublado', 'Foi jogar tênis'],
    ['Não','Alta','Média', 'Ensolarado', 'Não foi jogar tênis'],
    ['Não','Normal','Fria', 'Ensolarado', 'Foi jogar tênis'],
    ['Não','Normal','Média', 'Chuva', 'Foi jogar tênis'],
    ['Sim','Normal','Média', 'Ensolarado', 'Foi jogar tênis'],
    ['Sim','Alta','Média', 'Nublado', 'Foi jogar tênis'],
    ['Não','Normal','Quente', 'Nublado', 'Foi jogar tênis'],
    ['Sim','Alta','Média', 'Chuva', 'Não foi jogar tênis'],
]

cabecalhoArvore = ["Ventando", "Humidade", "Temperatura", "Tempo",  "label"]

def valoresUnicos(linhas, coluna):
    return set([row[coluna] for row in linhas])

def contaClasses(linhas):
    total = {}
    for linha in linhas:
        label = linha[-1]
        if label not in total:
            total[label] = 0
        total[label] += 1
    return total

def ehNumero(valor):
    return isinstance(valor, int) or isinstance(valor, float)

class Pergunta:
    def __init__(self, coluna, valor):
        self.coluna = coluna
        self.valor = valor

    def match(self, exemplo):
        val = exemplo[self.coluna]
        if ehNumero(val):
            return val >= self.valor
        else:
            return val == self.valor

    def __repr__(self):
        condicao = "=="
        if ehNumero(self.valor):
            condicao = ">="
        return "%s %s %s?" % (
            cabecalhoArvore[self.coluna], condicao, str(self.valor))

def partition(rows, question):
    true_rows, false_rows = [], []
    for row in rows:
        if question.match(row):
            true_rows.append(row)
        else:
            false_rows.append(row)
    return true_rows, false_rows

def gini(linhas):
    counts = contaClasses(linhas)
    impurity = 1
    for lbl in counts:
        prob_of_lbl = counts[lbl] / float(len(linhas))
        impurity -= prob_of_lbl**2
    return impurity

def info_gain(left, right, current_uncertainty):
    p = float(len(left)) / (len(left) + len(right))
    return current_uncertainty - p * gini(left) - (1 - p) * gini(right)

def find_best_split(rows):
    best_gain = 0
    best_question = None
    current_uncertainty = gini(rows)
    n_features = len(rows[0]) - 1

    for col in range(n_features):

        values = set([row[col] for row in rows])

        for val in values:
            question = Pergunta(col, val)

            true_rows, false_rows = partition(rows, question)

            if len(true_rows) == 0 or len(false_rows) == 0:
                continue

            gain = info_gain(true_rows, false_rows, current_uncertainty)

            if gain >= best_gain:
                best_gain, best_question = gain, question

    return best_gain, best_question

class Folha:
    def __init__(self, linhas):
        self.predictions = contaClasses(linhas)

class NoDecisao:
    def __init__(self,
                 question,
                 true_branch,
                 false_branch):
        self.question = question
        self.true_branch = true_branch
        self.false_branch = false_branch

def constroiArvore(rows):
    gain, question = find_best_split(rows)

    if gain == 0:
        return Folha(rows)

    true_rows, false_rows = partition(rows, question)

    true_branch = constroiArvore(true_rows)

    false_branch = constroiArvore(false_rows)

    return NoDecisao(question, true_branch, false_branch)

def mostraArvore(no, espaco=""):

    if isinstance(no, Folha):
        print (espaco + "Dado", no.predictions)
        return

    print (espaco + str(no.question))

    print (espaco + '-> Verdadeiro:')
    mostraArvore(no.true_branch, espaco + "  ")

    print (espaco + '-> Falso:')
    mostraArvore(no.false_branch, espaco + "  ")

arvore = constroiArvore(dados)

mostraArvore(arvore)
