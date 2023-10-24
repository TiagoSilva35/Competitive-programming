def magicstone_deckbuilder(cards, S, C, n, idx, selected_cards, selected_cost, selected_power):
    if S == 0:
        return selected_power, selected_cost, selected_cards
    if idx == n:
        return 0, selected_cost, selected_cards
    without_current = magicstone_deckbuilder(cards, S, C, n, idx + 1, selected_cards, selected_cost, selected_power)

    if cards[idx][1] <= C:
        with_current = magicstone_deckbuilder(cards, S - 1, C - cards[idx][1], n, idx + 1,
                                               selected_cards + [cards[idx][0]], selected_cost + cards[idx][1],
                                               selected_power + cards[idx][2] + cards[idx][3])
    else:
        with_current = (0, 0, [])

    if with_current[0] > without_current[0] or (with_current[0] == without_current[0] and with_current[1] <= without_current[1]):
        return with_current
    else:
        return without_current

def main():
    S = int(input())
    C = int(input())
    n = int(input())
    cards = []

    for _ in range(n):
        card_data = input().split()
        name = card_data[0]
        cost = int(card_data[1])
        attack = int(card_data[2])
        defense = int(card_data[3])
        cards.append((name, cost, attack, defense))

    selected_power, selected_cost, selected_cards = magicstone_deckbuilder(cards, S, C, n, 0, [], 0, 0)

    if selected_power > 0:
        #print(len(selected_cards))
        print(len(selected_cards),selected_power, selected_cost)
        for card in selected_cards:
            print(card)
    else:
        print("No Solution")

if __name__ == "__main__":
    main()
