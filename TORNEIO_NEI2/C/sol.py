def intersection_area():
    N = int(input().strip())
    rectangles = []
    for _ in range(N):
        x1, y1, x2, y2 = map(int, input().strip().split())
        rectangles.append((x1, y1, x2, y2))

    max_x1 = max(rectangle[0] for rectangle in rectangles)
    max_y1 = max(rectangle[1] for rectangle in rectangles)
    min_x2 = min(rectangle[2] for rectangle in rectangles)
    min_y2 = min(rectangle[3] for rectangle in rectangles)

    if max_x1 < min_x2 and max_y1 < min_y2:
        print((min_x2 - max_x1) * (min_y2 - max_y1))
    else:
        print(0)

intersection_area()