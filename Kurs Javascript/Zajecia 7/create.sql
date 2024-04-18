CREATE TABLE glosowanie.codes (
    id INT(10) unsigned NOT NULL AUTO_INCREMENT, 
    code VARCHAR(50),
    PRIMARY KEY (id)
    );

CREATE TABLE glosowanie.votes (
    id INT(10) unsigned NOT NULL AUTO_INCREMENT, 
    code VARCHAR(50),
    vote VARCHAR(50),
    PRIMARY KEY (id)
    );

CREATE TABLE glosowanie.data(
    id INT(10) unsigned NOT NULL AUTO_INCREMENT,
    country VARCHAR(50),
    votes INT(10),
    PRIMARY KEY(id)
    );