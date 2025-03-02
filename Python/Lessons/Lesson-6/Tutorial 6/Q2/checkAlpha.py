#CheckAlpha

def Alpha(word):
    out = 0
    if word.isalpha():
        out = 1
    else:
        out = 2
    return out