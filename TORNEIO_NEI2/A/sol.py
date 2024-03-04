def predict_double_response(S):
    return S[::-1]

S = input().strip()
print(predict_double_response(S))