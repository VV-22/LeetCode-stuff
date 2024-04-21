class Solution {
    public int canBeTypedWords(String text, String brokenLetters) 
    {
        String[] allWords = text.split(" ");
        String[] allLetters = brokenLetters.split("");
        if(brokenLetters.isEmpty())
            return allWords.length;
        int count = 0;
        for(int i = 0; i < allWords.length; i++)
        {
            boolean flag = true;
            for(int j = 0; j < allLetters.length; j++)
            {
                if(allWords[i].contains(allLetters[j]))
                    flag = false;
            }
            if(flag)
                count++;
        }

        return count;
    }
}