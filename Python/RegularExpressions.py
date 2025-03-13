import re

text = "The quick brown fox jumps over the lazy dog."

results = re.findall("[Tt]he", text)
text = re.sub("quick", "slow", text)
print(results)
print(text)