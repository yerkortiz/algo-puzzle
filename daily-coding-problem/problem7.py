"""
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable. For example, '001' is not allowed.
"""

n = input()
s = str(n)
solution_set = set()
for e in range(0, len(s)):
    x = int(s[e])
    if x not in solution_set:
        solution_set.add(x)
for e in range(1, len(s)):
    x = int(s[e - 1] + s[e])
    if 10 <= x <= 26 and x not in solution_set:
        solution_set.add(x)
print(solution_set)
print (len(solution_set))
