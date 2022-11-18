def calcula_preco_chamada(horario_inicio: int, horario_fim: int) -> float:
    min_faixa_1: int
    min_faixa_2: int
    valor_faixa_1: float = 0.40
    valor_faixa_2: float = 0.20
    if horario_fim < horario_inicio: raise Exception
    if horario_inicio < 0: raise Exception
    if horario_inicio > 24 * 60: raise Exception
    if horario_fim < 0: raise Exception
    if horario_fim > 24 * 60: raise Exception

    if horario_inicio < 8 * 60:
        if horario_fim < 8 * 60:
            min_faixa_2 = horario_fim - horario_inicio
            min_faixa_1 = 0
        elif horario_fim >= 8 * 60 and horario_fim <= 18 * 60:
            min_faixa_2 = 8 * 60 - horario_inicio
            min_faixa_1 = horario_fim - 8 * 60
        else:
            min_faixa_2 = horario_fim - horario_inicio - 10 * 60
            min_faixa_1 = 10 * 60
    elif horario_inicio >= 8 * 60 and horario_inicio <= 18 * 60:
        if horario_fim >= 8 * 60 and horario_fim <= 18 * 60:
            min_faixa_2 = 0
            min_faixa_1 = horario_fim - 8 * 60
        else:
            min_faixa_2 = horario_fim - 18 * 60
            min_faixa_1 = 18 * 60 - horario_inicio
    else:
        min_faixa_2 = horario_fim - horario_inicio
        min_faixa_1 = 0
    return min_faixa_1 * valor_faixa_1 + min_faixa_2 * valor_faixa_2
