# mimic reduce
# strings=['this','is','the','endgame']
# output: 'is'

strings = ['this', 'is', 'the', 'endgame']

smallest_string = strings[0] if strings else None

# bad design tho ;/
for s in strings[1:]: smallest_string = s if len(s) < len(smallest_string) else smallest_string
print(smallest_string)

