# TODO
import cs50

frase = cs50.get_string("Text: ")

letras=0
sentencas=0
palavras=0
whitespace=' '
end_of_sentences= ['!', '.', '?']

letras = len([ele for ele in frase if ele.isalpha()])
palavras=len([ele for ele in frase if ele==whitespace])+1
sentencas = len([ele for ele in frase if ele in end_of_sentences])
# if sentencas==0:
#     sentencas=1
# print("Palavras: "+str(palavras))
# print("Letras: " + str(letras))
# print("Sentencas: " + str(sentencas))
le=float(letras)
pa=float(palavras)
se=float(sentencas)


L=le*100/pa
S=se*100/pa

# print("L: {}".format(L))
# print("S: {}".format(S))

G=0.0588 * L - 0.296 * S - 15.8
print(G)
if G<0:
    grade=G-0.5
else:
    grade=G+0.5

grade1=int(grade)
if (grade < 1):
        print("Before Grade 1\n");
elif grade1>16:
    print("Grade: 16+")
else:
    print("Grade: {}".format(grade1))
