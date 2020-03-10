littlestar = '''Twinkle, twinkle, little star,
How I wonder what you are.
Up above the world so high
Like a diamond in the sky.
Twinkle, twinkle, little star,
How I wonder what you are.
When the blazing sun is gone,
When he nothing shines upon,
Then you show your little light,
Twinkle, twinkle, all the night.
Twinkle, twinkle, little star,
How I wonder what you are.
Then the traveler in the dark,
Thanks you for your tiny spark,
He could not see where to go,
If you did not twinkle so.
Twinkle, twinkle, little star,
How I wonder what you are.
In the dark blue sky you keep,
Often through my curtains peep.
For you never shut your eye,
Till the sun is in the sky.
Twinkle, twinkle, little star,
How I wonder what you are.'''
littlestar = littlestar.lower()
wordlist = {}
tempword = ''
for char in littlestar:
    if char == ' ' or char == ',' or char == '.' or char == '\n':
        if tempword == '':
            pass
        elif tempword in wordlist:
            wordlist[tempword] = wordlist[tempword] + 1
        else:
            wordlist[tempword] = 1
        tempword = ''
    else:
        tempword = tempword + char

for item in wordlist:
    print('%s %d' % (item, wordlist[item]))
