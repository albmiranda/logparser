import json
import os


## Print grouped information

dirname = os.path.dirname(__file__) #<-- absolute dir the script is in
absolute_file_path = os.path.join(dirname, "../out/match.rec")
absolute_json_path = os.path.join(dirname, "../out/match.json")

## by default the record file isn't json format, so is necessary a convertion
with open(absolute_file_path,"r+") as f, open(absolute_json_path, "a+") as f_json:
    f_json.write("[")
    f_json.write(f.read())
    f_json.write("]")

f_json = open(absolute_json_path, "r+")

obj = json.load(f_json)
formatted_str = json.dumps(obj, indent=3)

print(formatted_str)


## Creating ranking

ranking = dict()
for game in obj:
    for player, nKills in game["kills"].items():
        if player in ranking:
            ranking[player] = ranking[player] + nKills
        else:
            ranking[player] = nKills

sorted_ranking = sorted(ranking.items(), key=lambda x:x[1], reverse=True)

print("###### RANKING - NUMBER OF KILLS ######")
position = 1
for i in sorted_ranking:
    print(position, "-", i[0], ":", i[1])
    position += 1


f_json.close()