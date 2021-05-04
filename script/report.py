import json
import os

def convert_record_into_json(original_file_path, json_file_path):
    """ By default the record file with game match information isn't json format.
    A convertion to json file makes easier to manipulate the file data.

    Args:
        original_file_path: original game match information file
        json_file_path: game match information file in json format
    """
    with open(original_file_path,"r+") as f, open(json_file_path, "a+") as f_json:
        f_json.write("[")
        f_json.write(f.read())
        f_json.write("]")


def show_record_report(obj):
    """ Prints information about all game match individually

    Args:
        obj: a JSON object
    """
    formatted_str = json.dumps(obj, indent=3)
    print(formatted_str)


def create_ranking_of_killers(json_obj):
    """ From all game match creates a sorted ranking of killers

    Args:
        json_obj: a JSON object whose content is game match information
    Return:
        a dictionary representing the ranking of killers
    """
    ranking = dict()
    for game in json_obj:
        for player, nKills in game["kills"].items():
            if player in ranking:
                ranking[player] = ranking[player] + nKills
            else:
                ranking[player] = nKills

    return sorted(ranking.items(), key=lambda x:x[1], reverse=True)


def pretty_print_ranking(ranking):
    """ Prints a ordered ranking in pretty way.

    Args:
        ranking: a ordered ranking
    """
    position = 1
    for i in ranking:
        print(position, "-", i[0], ":", i[1])
        position += 1


if __name__ == "__main__":

    dirname = os.path.dirname(__file__)
    absolute_file_path = os.path.join(dirname, "../out/match.rec")
    absolute_json_path = os.path.join(dirname, "../out/match.json")

    convert_record_into_json(absolute_file_path, absolute_json_path)

    with open(absolute_json_path,"r+") as json_file:
        obj = json.load(json_file)

        print("###### GAME MATCHES REPORT ######\n")
        show_record_report(obj)

        print("###### RANKING - NUMBER OF KILLS ######\n")
        ranking_players = create_ranking_of_killers(obj)
        pretty_print_ranking(ranking_players)



    print("###### DEATH CAUSE REPORT ######")
    absolute_deaths_file_path = os.path.join(dirname, "../out/match.rec_deathcause")
    absolute_deaths_json_path = os.path.join(dirname, "../out/match_deathcause.json")
    convert_record_into_json(absolute_deaths_file_path, absolute_deaths_json_path)

    with open(absolute_deaths_json_path,"r+") as json_file:
        obj = json.load(json_file)
        show_record_report(obj)
