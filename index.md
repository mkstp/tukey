## The Tukey Keyboard Layout - BASE LAYER

Named after the famous statistician John Tukey (pronounced too-key). This layout is designed for a minimum 42key, multi-layered, QMK compatible ortholinear keyboard like the [Planck](https://olkb.com/collections/planck).

![image](letters_layout.png)

The Tukey layout does away with the assumption that each letter/symbol should occupy only one position on the keyboard. For example, the letters 'O', 'L', 'R', and 'T' appear twice in the image. There is also the addition of a dedicated 'REPEAT' key in the top left corner of the keyboard. 

This duplication of select letters, the repeat key, and the data driven principles that support their design, is what inspired the name 'Tukey'.

### Why Duplicate Keys?

Layouts like Colemak are designed to minimize same finger bigrams (SFB's). That is, keys typed sequentially using the same finger. On a QWERTY keyboard for example, 'CE' is a SFB, so is 'DE' and 'RT'. When typing, a SFB takes longer to execute than keys typed sequentially using two different fingers. A SFB requires you to press the first key, then raise your finger before moving to and pressing the next key. With two different fingers, pressing a key and positioning your other finger to press the next key can happen at the same time, which results in faster, smoother, and more accurate typing. 

No perfect layout exists which completely eliminates SFB's, and so designers try to position letters in a way that matches the least common bigrams to SFB positions on a keyboard. This is why 'F' and 'H' are positioned where they are on this layout, since they almost never appear right next to each other it is therefore safer to place them within the same finger range on the board. It's a better design choice than 'DE' on a QWERTY keyboard for example, which is an extremely common bigram that, unfortunately must be typed with the same finger. 

The chief justification for duplicating keys at different positions on the keyboard is that double letter bigrams (DLB's) like 'OO' and 'LL' are also, by convention, same finger bigrams. And as a result of this convention they are inefficient to type. They are also extremely common. In fact, in the aggregate, DLB's account for over 2.5% of all bigrams typed in the english language. That makes them the third most common bigram after 'TH' (3.5%) and 'HE' (3.1%). 

### The Repeat Key

The repeat key addresses all double letter bigrams with the exception of 'AA' and 'QQ' which require extra left pinky finger motion. With it, you will find that your hands glide over the keyboard when typing words like 'difficult' or 'successful' instead of what would normally feel like a game of hop scotch with your hands. This key will store and repeat any previous action inputted to the keyboard, which means it also works for macros like copy/paste and other shortcuts. Implementation for the key can be found [here](https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131)

### O L R and T

So if the repeat key exists to type DLB's, then why are there other duplicate keys still scattered over the keyboard? That's because the position of select duplicate letters helps to further reduce SFB's to near zero for a seamless typing experience. For each duplicate key: 

- 'O' addresses the 'EO' and 'OA' bigram conflicts, which helps with words like 'people', 'does', and 'board'. 
- 'L' helps with 'LE' and 'LN' when typing words like 'only', 'learn', and 'leave'
- 'R' helps with 'RI' and 'RS' when typing words like 'right', 'describe', and 'person' 
- 'T' helps with 'PT' and 'TE' when typing words like 'accept', 'option', and 'captain'

For other potential conflicts, there is usually an easy way to reposition your fingers to avoid a SFB. For example, the words 'small' or 'kept' require slight inward lateral shifts from the traditional home row finger positions. The words 'first' and 'write' as well. Slightly more challenging are words like 'member', 'question' or 'yield' which may require you to layer your fingers while turning your wrists inward.  

Sadly, there are still a good number of SFB's that I could not address with duplicate letters or 'creative ergonomics'. These are expressed in the table below, along with their relative percent frequencies:

| Bigram | Percent Frequency |
| ------ | ----------------- |
| WS | 0.035% |
| SW | 0.024% |
| NX | 0.003% |
| DC | 0.003% |
| CD | 0.002% |
| AQ | 0.002% |
| HF | 0.002% |
| ZP | 0.000% |
| JH | 0.000% |
| FJ | 0.000% |
| PZ | 0.000% |
| XN | 0.000% |
| QA | 0.000% |
| FH | 0.000% |
| HJ | 0.000% |
| TOTAL | 0.071% |

By comparison, we can apply the same 'creative ergonomic' strategies to Colemak Mod-DH which reduces its SFB frequency to 3.018% (this includes the aforementioned 2.5% duplicate key frequency of course). Which makes the Tukey layout arguably better than Colemak for SFB's. Notable conflicts with Colemak Mod-DH include 'UE' and 'EU', 'PT' and 'TP', 'WR' and 'RW' among others. 

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for

```markdown
Syntax highlighted code block

# Header 1
## Header 2
### Header 3

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)
```

For more details see [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/mkstp/tukey/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
