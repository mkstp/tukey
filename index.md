## The Tukey Keyboard Layout - BASE LAYER

Named after the famous statistician John Tukey (pronounced too-key). This layout is designed for a minimum 42key, multi-layered, QMK compatible ortholinear keyboard like the [Planck](https://olkb.com/collections/planck).

![image](letters_layout.png)

The Tukey layout does away with the assumption that each letter/symbol should occupy only one position on the keyboard. For example, the letters 'O', 'L', 'R', and 'T' appear twice in the image. There is also the addition of a dedicated 'REPEAT' key in the top left corner of the keyboard. 

This duplication of select letters, the repeat key, and the data driven principles that support their design, is what inspired the name 'Tukey'.

### Why Duplicate Keys?

Layouts like Colemak are designed to minimize same finger bigrams (SFB's). That is, keys typed sequentially using the same finger. On a QWERTY keyboard for example, 'CE' is a SFB, so is 'DE' and 'RT'. When typing, a SFB takes longer to execute than keys typed sequentially using two different fingers. A SFB requires you to press the first key, then raise your finger before moving to and pressing the next key. With two different fingers, pressing a key and positioning your other finger to press the next key can happen at the same time, which results in faster, smoother, and more accurate typing. 

No perfect layout exists which completely eliminates SFB's, and so designers try to position letters in a way that matches the least common bigrams to SFB positions on a keyboard. This is why 'F' and 'H' are positioned where they are on this layout, since they almost never appear right next to each other it is therefore safer to place them within the same finger range on the board. It's a better design choice than 'DE' on a QWERTY keyboard for example, which is an extremely common bigram that unfortunately must be typed with the same finger. 

The chief justification for duplicating keys at different positions on the keyboard is that double letter bigrams (DLB's) like 'OO' and 'LL' are also, by convention, same finger bigrams. And as a result of this convention they are inefficient to type. They are also extremely common. In fact, in the aggregate, DLB's account for over 2.5% of all bigrams typed in the english language. That makes them the third most common bigram after 'TH' (3.5%) and 'HE' (3.1%). 

### The Repeat Key

The repeat key decouples same finger bigrams from all double letter bigrams with the exception of 'AA' and 'QQ' which require extra left pinky finger motion. This key will repeat any previous action inputted to the keyboard, which means it also works for macros like copy/paste and other shortcuts. With it, you will find that your fingers glide over the keyboard when typing words like 'difficult' or 'successful' instead of what would normally feel like a game of hop scotch with your hands. The QMK implementation for the key can be found [here](https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131)

### O L R and T

So if the repeat key exists to type DLB's, then why are there other duplicate keys still scattered over the keyboard? That's because the position of select duplicate letters helps to further reduce SFB's to near zero for a seamless typing experience. For each duplicate key: 

- 'O' addresses the 'EO' and 'OA' bigram conflicts, which helps with words like 'people', 'does', and 'board'. 
- 'L' helps with 'LE' and 'LN' when typing words like 'only', 'learn', and 'leave'
- 'R' helps with 'RI' and 'RS' when typing words like 'right', 'describe', and 'person' 
- 'T' helps with 'PT' when typing words like 'accept', 'option', and 'captain'

### Unconventional Ergonomics

For other potential conflicts, there is usually an easy way to reposition your fingers to avoid a SFB. For example, the words 'small' or 'kept' require slight inward lateral shifts from the traditional home row finger positions. The words 'first' and 'write' as well. Slightly more challenging are words like 'member', 'question' and 'bring' which require you to layer your fingers while turning your wrists inward. And the nearly impossible to avoid SFB's are in words like 'answer', 'yield' or 'phalanx'. 

### Inward Finger Rolls

Inward rolls were an additional design priority for this layout. When rolling your fingers on a desk, it's more likely that you roll them from your pinky finger to your index instead of the other way around. And so with Tukey, keys were placed in prime locations on the home row based on their frequency, but they were also placed laterally with letters that are more likely to be at the beginning of words on the outermost ends of the board. For example, on the home row it's very easy to type 'and' and 'the', the most common words in english, by naturally rolling your fingers inward. To get a better feel for how Tukey's inward rolls can improve your typing experience, try typing: 

"The old friends from France held hands"

### Tradeoffs

With a smaller number of physical keys, more complex layering schemas are necessary to achieve the full breadth of key inputs needed for typing. Admittedly, the Tukey layout does not align with the modern trend in custom keyboard design to reduce the number of keys on the keyboard as much as possible (I think the record is 34 keys as of late 2020). In my opinion, the pursuit of the smallest keyboard produces more complex layouts, and there's a subjective point for any user where its complexity makes the keyboard too difficult to use. For me, I believe in a more balanced approach which accepts some complexity in layering while trying to preserve a maximum finger travel distance of 1U away from the home position. But it stops at 40% of a normal keyboard. Beyond that point my main design principle of not typing two keys with the same finger becomes very difficult to mitigate. 

What results is the absence of common punctuation like ',' and '.' on the base layer. 
