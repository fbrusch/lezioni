def leggi_parole(nomefile):
    stringa_parole = open(nomefile).read()
    parole = stringa_parole.split("\n")
    return parole[0:-1]

def is_anagramma(word1, word2):
    return sorted(word1) == sorted(word2)

def is_carattere_meno(word1, word2):
    for i in range(len(word1)):
        if word1[:i]+word1[i+1:] == word2:
            return True
    return False

def is_carattere_piu(word1, word2):
    return is_carattere_meno(word2,word1)

def num_divs(word1, word2):
    count = 0
    if len(word1) != len(word2):
        return -1
    for i in range(len(word1)):
        if word1[i]!=word2[i]:
            count = count +1
    return count

def is_carattere_cambiato(word1, word2):
    return num_divs(word1,word2) == 1

def is_prossimo(word1, word2):
    return is_carattere_cambiato(word1,word2) or \
           is_carattere_meno(word1, word2) or\
           is_carattere_piu(word1, word2) or\
           is_anagramma(word1,word2)

def prossimi(parola, parole):
    return [pr for pr in parole if is_prossimo(parola,pr)]
