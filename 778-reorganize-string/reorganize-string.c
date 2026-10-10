char* reorganizeString(char* s)
{
    int freq[26] = {0};
    int n = strlen(s);

    // Count frequency of each character
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    // Find maximum frequency
    int maxFreq = 0;
    int maxChar = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            maxChar = i;
        }
    }

    // Check whether rearrangement is possible
    if (maxFreq > (n + 1) / 2)
    {
        return "";
    }

    char *result = malloc((n + 1) * sizeof(char));

    int pos = 0;

    // Put the most frequent character first
    while (freq[maxChar] > 0)
    {
        result[pos] = 'a' + maxChar;
        pos += 2;
        freq[maxChar]--;
    }

    // Put remaining characters
    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {
            if (pos >= n)
                pos = 1;

            result[pos] = 'a' + i;
            pos += 2;
            freq[i]--;
        }
    }

    result[n] = '\0';

    return result;
}