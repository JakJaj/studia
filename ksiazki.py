# Input list
book_list = """
The Great Expectations;Charles Dickens;2;15.99;Classic novel following the life of an orphan named Pip.
The Road Less Traveled;M. Scott Peck;1;12.99;Psychological and spiritual guide to personal growth.
The Color Purple;Alice Walker;1;11.99;Compelling narrative of African American women's struggles in the early 20th century.
The Outsiders;S.E. Hinton;1;9.99;Coming-of-age novel exploring the rivalry between two groups of teenagers.
The Sun Also Rises;Ernest Hemingway;1;10.99;Post-World War I novel capturing the disillusionment of the "Lost Generation."
Fahrenheit 451;Ray Bradbury;1;8.99;Dystopian tale depicting a future society where books are banned.
Sapiens;Yuval Noah Harari;1;14.99;Historical exploration of the evolution of Homo sapiens and the impact on the world.
The Handmaid's Tale;Margaret Atwood;1;13.99;Dystopian narrative about a woman's struggle for survival in a theocratic society.
The Old Man and the Sea;Ernest Hemingway;1;9.99;Novella depicting an aging Cuban fisherman's battle with a giant marlin.
The Silent Patient;Alex Michaelides;1;11.99;Psychological thriller centered around a woman's sudden act of violence.
The Joy Luck Club;Amy Tan;1;12.99;Interwoven stories of Chinese-American immigrant families in the United States.
The Road to Wigan Pier;George Orwell;1;10.99;Social commentary on the living conditions of the working class in England.
The Fault in Our Stars;John Green;1;11.99;Heartbreaking romance between two teenagers dealing with cancer.
The God of Small Things;Arundhati Roy;1;14.99;Family saga set in post-colonial India, exploring love, caste, and social norms.
The Poisonwood Bible;Barbara Kingsolver;1;13.99;Tale of a missionary family's journey to the Congo and its consequences.
The Immortal Life of Henrietta Lacks;Rebecca Skloot;1;12.99;Nonfiction account of the impact of HeLa cells on medical science.
The Road to Character;David Brooks;1;15.99;Reflection on the importance of building inner character in a materialistic world.
The Book Thief;Markus Zusak;1;11.99;Narrated by Death, this novel tells the story of a girl in Nazi Germany.
The Martian;Andy Weir;1;14.99;Science fiction novel about an astronaut stranded on Mars and his fight for survival.
The Girl on the Train;Paula Hawkins;1;10.99;Thriller revolving around a woman who becomes entangled in a missing person's investigation.
The Nightingale;Kristin Hannah;1;13.99;Historical fiction set during World War II, focusing on two sisters in France.
The Art of War;Sun Tzu;1;8.99;Ancient Chinese treatise on military strategy and tactics.
The Count of Monte Cristo;Alexandre Dumas;1;15.99;Adventure novel of betrayal, revenge, and redemption in 19th-century France.
The Three Musketeers;Alexandre Dumas;1;11.99;Classic adventure tale of friendship and intrigue in 17th-century France.
The Road Not Taken;Robert Frost;1;7.99;Collection of poems by the renowned American poet.
The Picture of Dorian Gray;Oscar Wilde;1;10.99;Philosophical novel exploring the consequences of a life of excess and vanity.
The Glass Castle;Jeanette Walls;1;12.99;Memoir depicting the author's unconventional and challenging childhood.
The Circle;Dave Eggers;1;13.99;Dystopian novel exploring the implications of a powerful tech company's influence.
The Immortalists;Chloe Benjamin;1;11.99;Novel following four siblings who learn the dates of their deaths from a fortune teller.
The Big Short;Michael Lewis;1;14.99;Nonfiction account of the 2008 financial crisis and those who saw it coming.
The Night Circus;Erin Morgenstern;1;12.99;Fantasy novel set in a magical competition between two illusionists.
The Help;Kathryn Stockett;1;11.99;Historical novel exploring the lives of African American maids in 1960s Mississippi.
The Immortal Rules;Julie Kagawa;1;9.99;Young adult novel set in a dystopian world where vampires rule.
The Goldfinch;Donna Tartt;1;14.99;Pulitzer Prize-winning novel about a young boy's journey after a tragedy.
The Wind-Up Bird Chronicle;Haruki Murakami;1;13.99;Surreal and mysterious novel exploring a man's search for his missing wife.
The Catcher in the Rye;J.D. Salinger;1;11.99;Coming-of-age novel following Holden Caulfield's adventures in New York City.
The Hobbit;J.R.R. Tolkien;1;14.99;Fantasy classic featuring the journey of Bilbo Baggins.
The Girl with the Dragon Tattoo;Stieg Larsson;3;29.99;Thriller featuring journalist Mikael Blomkvist and hacker Lisbeth Salander.
The Hunger Games;Suzanne Collins;3;26.99;Dystopian trilogy following Katniss Everdeen's fight for survival.
The Alchemist;Paulo Coelho;1;9.99;Philosophical novel about a shepherd's journey to find his personal legend.
Brave New World;Aldous Huxley;1;10.99;Dystopian vision of a future society controlled by technology.
The Da Vinci Code;Dan Brown;4;39.99;Mystery thriller involving symbologist Robert Langdon.
The Shining;Stephen King;2;21.99;Horror novel set in the haunted Overlook Hotel.
The Road;Cormac McCarthy;1;12.99;Post-apocalyptic journey of a father and son through a desolate landscape.
Gone with the Wind;Margaret Mitchell;1;14.99;Epic tale set during the American Civil War and Reconstruction.
Crime and Punishment;Fyodor Dostoevsky;1;10.99;Psychological novel exploring morality and guilt.
The Odyssey;Homer;1;12.99;Ancient Greek epic poem following Odysseus' journey home.
The Brothers Karamazov;Fyodor Dostoevsky;1;14.99;Philosophical novel examining the nature of faith and doubt.
The Scarlet Letter;Nathaniel Hawthorne;1;8.99;Classic tale of sin, guilt, and redemption in Puritan New England.
The Picture of Dorian Gray;Oscar Wilde;1;11.99;Philosophical novel exploring the consequences of a life of excess and vanity.
The Master and Margarita;Mikhail Bulgakov;1;13.99;Satirical novel blending fantasy and reality in Soviet Moscow.
The Sound and the Fury;William Faulkner;1;9.99;Modernist novel exploring the Compson family's decline in the South.
The Stranger;Albert Camus;1;10.99;Existentialist novel examining the absurdity of human existence.
The Handmaid's Tale;Margaret Atwood;1;11.99;Dystopian narrative about a woman's struggle for survival in a theocratic society.
One Hundred Years of Solitude;Gabriel García Márquez;1;12.99;Magical realist saga of the Buendía family in Macondo.
Beloved;Toni Morrison;1;14.99;Powerful novel addressing the legacy of slavery in post-Civil War America.
The Picture of Dorian Gray;Oscar Wilde;1;16.99;Philosophical novel exploring the consequences of a life of excess and vanity.
Crime and Punishment;Fyodor Dostoevsky;1;17.99;Psychological novel exploring morality and guilt.
The Grapes of Wrath;John Steinbeck;1;18.99;Powerful story of the Joad family during the Great Depression.
The Name of the Wind;Patrick Rothfuss;1;19.99;Fantasy novel chronicling the life of the legendary Kvothe.
The Goldfinch;Donna Tartt;1;20.99;Pulitzer Prize-winning novel about a young boy's journey after a tragedy.
The Handmaid's Tale;Margaret Atwood;1;21.99;Dystopian narrative about a woman's struggle for survival in a theocratic society.
The Shadow of the Wind;Carlos Ruiz Zafón;1;22.99;Mystery novel set in post-war Barcelona centered around a forgotten book.
The Martian;Andy Weir;1;23.99;Science fiction novel about an astronaut stranded on Mars and his fight for survival.
The Night Circus;Erin Morgenstern;1;24.99;Fantasy novel set in a magical competition between two illusionists.
The Immortal Life of Henrietta Lacks;Rebecca Skloot;1;25.99;Nonfiction account of the impact of HeLa cells on medical science.
The Road;Cormac McCarthy;1;26.99;Post-apocalyptic journey of a father and son through a desolate landscape.
The Road Less Traveled;M. Scott Peck;1;27.99;Psychological and spiritual guide to personal growth.
The Brothers Karamazov;Fyodor Dostoevsky;1;28.99;Philosophical novel examining the nature of faith and doubt.
The Art of War;Sun Tzu;1;29.99;Ancient Chinese treatise on military strategy and tactics.
The Name of the Wind;Patrick Rothfuss;1;30.99;Fantasy novel chronicling the life of the legendary Kvothe.
The Shadow of the Wind;Carlos Ruiz Zafón;1;31.99;Mystery novel set in post-war Barcelona centered around a forgotten book.
The Silent Patient;Alex Michaelides;1;32.99;Psychological thriller centered around a woman's sudden act of violence.
The Goldfinch;Donna Tartt;1;33.99;Pulitzer Prize-winning novel about a young boy's journey after a tragedy.
The Three Musketeers;Alexandre Dumas;1;34.99;Classic adventure tale of friendship and intrigue in 17th-century France.
The Count of Monte Cristo;Alexandre Dumas;1;35.99;Adventure novel of betrayal, revenge, and redemption in 19th-century France.
The Sound and the Fury;William Faulkner;1;36.99;Modernist novel exploring the Compson family's decline in the South.
The Immortal Life of Henrietta Lacks;Rebecca Skloot;1;37.99;Nonfiction account of the impact of HeLa cells on medical science.
The Picture of Dorian Gray;Oscar Wilde;1;38.99;Philosophical novel exploring the consequences of a life of excess and vanity.
The Name of the Wind;Patrick Rothfuss;1;39.99;Fantasy novel chronicling the life of the legendary Kvothe.
The Immortal Life of Henrietta Lacks;Rebecca Skloot;1;40.99;Nonfiction account of the impact of HeLa cells on medical science.
The Brothers Karamazov;Fyodor Dostoevsky;1;41.99;Philosophical novel examining the nature of faith and doubt.
The Road Less Traveled;M. Scott Peck;1;42.99;Psychological and spiritual guide to personal growth.
The Count of Monte Cristo;Alexandre Dumas;1;43.99;Adventure novel of betrayal, revenge, and redemption in 19th-century France.
The Picture of Dorian Gray;Oscar Wilde;1;44.99;Philosophical novel exploring the consequences of a life of excess and vanity.
The Shadow of the Wind;Carlos Ruiz Zafón;1;45.99;Mystery novel set in post-war Barcelona centered around a forgotten book.
The Three Musketeers;Alexandre Dumas;1;46.99;Classic adventure tale of friendship and intrigue in 17th-century France.
The Great Gatsby;F. Scott Fitzgerald;1;47.99;Jazz Age tale of wealth, love, and tragedy.
The Road;Cormac McCarthy;1;48.99;Post-apocalyptic journey of a father and son through a desolate landscape.
The Martian;Andy Weir;1;49.99;Science fiction novel about an astronaut stranded on Mars and his fight for survival.
The Silent Patient;Alex Michaelides;1;50.99;Psychological thriller centered around a woman's sudden act of violence.
The Sound and the Fury;William Faulkner;1;51.99;Modernist novel exploring the Compson family's decline in the South.
The Art of War;Sun Tzu;1;52.99;Ancient Chinese treatise on military strategy and tactics.
To Kill a Mockingbird;Harper Lee;1;10.99;Classic novel addressing racial injustice in the American South.
1984;George Orwell;1;12.99;Dystopian novel depicting a totalitarian future society.
The Lord of the Rings;J.R.R. Tolkien;3;29.99;Epic fantasy trilogy following the quest to destroy the One Ring.
Pride and Prejudice;Jane Austen;1;8.99;Classic romance novel exploring social class and love.
The Chronicles of Narnia;C.S. Lewis;7;49.99;Fantasy series chronicling the adventures in the magical land of Narnia.
The Great Gatsby;F. Scott Fitzgerald;1;11.99;Jazz Age tale of wealth, love, and tragedy.
The Catcher in the Rye;J.D. Salinger;1;10.99;Coming-of-age novel following Holden Caulfield's adventures in New York City.
The Hobbit;J.R.R. Tolkien;1;12.99;Fantasy classic featuring the journey of Bilbo Baggins.
The Grapes of Wrath;John Steinbeck;1;13.99;Powerful story of the Joad family during the Great Depression.
One Hundred Years of Solitude;Gabriel García Márquez;1;14.99;Magical realist saga of the Buendía family in Macondo.
The Kite Runner;Khaled Hosseini;1;15.99;Emotional novel set in Afghanistan exploring friendship and redemption.
The Girl with the Dragon Tattoo;Stieg Larsson;1;16.99;Thriller featuring journalist Mikael Blomkvist and hacker Lisbeth Salander.
The Hunger Games;Suzanne Collins;1;17.99;Dystopian novel following Katniss Everdeen's fight for survival.
The Alchemist;Paulo Coelho;1;18.99;Philosophical novel about a shepherd's journey to find his personal legend.
Brave New World;Aldous Huxley;1;19.99;Dystopian vision of a future society controlled by technology.
The Da Vinci Code;Dan Brown;1;20.99;Mystery thriller involving symbologist Robert Langdon.
The Shining;Stephen King;1;21.99;Horror novel set in the haunted Overlook Hotel.
The Road;Cormac McCarthy;1;22.99;Post-apocalyptic journey of a father and son through a desolate landscape.
Gone with the Wind;Margaret Mitchell;1;23.99;Epic tale set during the American Civil War and Reconstruction.
Wuthering Heights;Emily Brontë;1;24.99;Passionate tale of love and revenge on the Yorkshire moors.
Crime and Punishment;Fyodor Dostoevsky;1;25.99;Psychological novel exploring morality and guilt.
The Odyssey;Homer;1;26.99;Ancient Greek epic poem following Odysseus' journey home.
The Brothers Karamazov;Fyodor Dostoevsky;1;27.99;Philosophical novel examining the nature of faith and doubt.
The Scarlet Letter;Nathaniel Hawthorne;1;28.99;Classic tale of sin, guilt, and redemption in Puritan New England.
The Picture of Dorian Gray;Oscar Wilde;1;29.99;Philosophical novel exploring the consequences of a life of excess and vanity.
The Master and Margarita;Mikhail Bulgakov;1;30.99;Satirical novel blending fantasy and reality in Soviet Moscow.
The Sound and the Fury;William Faulkner;1;31.99;Modernist novel exploring the Compson family's decline in the South.
The Stranger;Albert Camus;1;32.99;Existentialist novel examining the absurdity of human existence.
Beloved;Toni Morrison;1;33.99;Powerful novel addressing the legacy of slavery in post-Civil War America.
The Name of the Wind;Patrick Rothfuss;1;34.99;Fantasy novel chronicling the life of the legendary Kvothe.
The Shadow of the Wind;Carlos Ruiz Zafón;1;35.99;Mystery novel set in post-war Barcelona centered around a forgotten book.
The Immortal Life of Henrietta Lacks;Rebecca Skloot;1;36.99;Nonfiction account of the impact of HeLa cells on medical science.
The Art of War;Sun Tzu;1;37.99;Ancient Chinese treatise on military strategy and tactics.
The Name of the Wind;Patrick Rothfuss;1;38.99;Fantasy novel chronicling the life of the legendary Kvothe.
The Shadow of the Wind;Carlos Ruiz Zafón;1;39.99;Mystery novel set in post-war Barcelona centered around a forgotten book.
To Kill a Mockingbird;Harper Lee;1;40.99;Classic novel addressing racial injustice in the American South.
1984;George Orwell;1;41.99;Dystopian novel depicting a totalitarian future society.
The Lord of the Rings;J.R.R. Tolkien;3;42.99;Epic fantasy trilogy following the quest to destroy the One Ring.
Pride and Prejudice;Jane Austen;1;43.99;Classic romance novel exploring social class and love.
The Chronicles of Narnia;C.S. Lewis;7;44.99;Fantasy series chronicling the adventures in the magical land of Narnia.
The Great Gatsby;F. Scott Fitzgerald;1;45.99;Jazz Age tale of wealth, love, and tragedy.
The Catcher in the Rye;J.D. Salinger;1;46.99;Coming-of-age novel following Holden Caulfield's adventures in New York City.
The Hobbit;J.R.R. Tolkien;1;47.99;Fantasy classic featuring the journey of Bilbo Baggins.
The Grapes of Wrath;John Steinbeck;1;48.99;Powerful story of the Joad family during the Great Depression.
One Hundred Years of Solitude;Gabriel García Márquez;1;49.99;Magical realist saga of the Buendía family in Macondo.
The Kite Runner;Khaled Hosseini;1;50.99;Emotional novel set in Afghanistan exploring friendship and redemption.
The Girl with the Dragon Tattoo;Stieg Larsson;1;51.99;Thriller featuring journalist Mikael Blomkvist and hacker Lisbeth Salander.
The Hunger Games;Suzanne Collins;1;52.99;Dystopian novel following Katniss Everdeen's fight for survival
"""

# Split the input into lines
lines = book_list.strip().split('\n')

# Use a set to keep track of seen lines
seen_lines = set()

# Filter out duplicate lines
unique_lines = [line for line in lines if line not in seen_lines and not seen_lines.add(line)]

# Join the unique lines into a single string
unique_book_list = '\n'.join(unique_lines)

# Print the result
print(unique_book_list)