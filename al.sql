--5
CREATE OR REPLACE PROCEDURE delete_pokemon_with_low_stats(p_threshold NUMBER)
IS
BEGIN
    DELETE FROM pokemon
    WHERE (hp + attack + defense + speed) < p_threshold;

    COMMIT;
END;
/
CREATE OR REPLACE PROCEDURE add_pokemon_to_trainer(
    p_trainer_id NUMBER,
    p_pokemon_id NUMBER
)
IS
BEGIN
    INSERT INTO owner (trainer_id, pokemon_id)
    VALUES (p_trainer_id, p_pokemon_id);
    
    COMMIT;
END;
/
CREATE OR REPLACE FUNCTION avg_attack_power(p_pokemon_name VARCHAR2) 
RETURN NUMBER
IS
    v_avg_power NUMBER;
BEGIN
    SELECT AVG(a.attack_power)
    INTO v_avg_power
    FROM pokemon p
    JOIN pokemon_attacks pa ON p.pokemon_id = pa.pokemon_id
    JOIN attacks a ON pa.attack_id = a.attack_id
    WHERE p.name = p_pokemon_name AND a.attack_power > 40;
    
    RETURN NVL(v_avg_power, 0); -- Return 0 if no valid attacks
END;
/
CREATE OR REPLACE PROCEDURE add_trainer_with_pokemon(
    p_trainer_id NUMBER,
    p_first_name VARCHAR2,
    p_last_name VARCHAR2,
    p_pokemon_id NUMBER
)
IS
BEGIN
    -- Insert Trainer
    INSERT INTO trainer (trainer_id, first_name, last_name)
    VALUES (p_trainer_id, p_first_name, p_last_name);
    
    -- Assign Pokémon to Trainer
    INSERT INTO owner (trainer_id, pokemon_id)
    VALUES (p_trainer_id, p_pokemon_id);
    
    COMMIT;
END;
/
CREATE OR REPLACE FUNCTION avg_attack_power(p_pokemon_name VARCHAR2) 
RETURN NUMBER
IS
    v_avg_power NUMBER;
BEGIN
    SELECT AVG(a.attack_power)
    INTO v_avg_power
    FROM pokemon p
    JOIN pokemon_attacks pa ON p.pokemon_id = pa.pokemon_id
    JOIN attacks a ON pa.attack_id = a.attack_id
    WHERE p.name = p_pokemon_name AND a.attack_power > 40;
    
    RETURN NVL(v_avg_power, 0); -- Return 0 if no valid attacks
END;
/
--add foreign key constraints
ALTER TABLE customer_dish 
ADD CONSTRAINT fk_customer FOREIGN KEY (cust_id) 
REFERENCES customer(cust_id);

ALTER TABLE customer_dish 
ADD CONSTRAINT fk_dish FOREIGN KEY (dish_id) 
REFERENCES dish(dish_id);
SELECT * FROM dish
WHERE dish_name LIKE '% % %' AND dish_name NOT LIKE '% % % %';
SELECT * FROM dish
WHERE dish_name LIKE '%Roll%';
--pl sql task soln
-- Task 1(a): Print your name and student ID.
BEGIN
    DBMS_OUTPUT.PUT_LINE('Name: Your_Name');
    DBMS_OUTPUT.PUT_LINE('Student ID: Your_Student_ID');
END;
/

-- Task 1(b): Take two numbers as input and print their product.
DECLARE
    num1 NUMBER;
    num2 NUMBER;
    product NUMBER;
BEGIN
    num1 := &num1;
    num2 := &num2;
    product := num1 * num2;
    DBMS_OUTPUT.PUT_LINE('Product: ' || product);
END;
/

-- Task 1(c): Take a number as input and print whether it is a whole number or a fraction.
DECLARE
    num NUMBER;
BEGIN
    num := &num;
    IF num = TRUNC(num) THEN
        DBMS_OUTPUT.PUT_LINE('Whole Number');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Fraction');
    END IF;
END;
/

-- Task 2: Execute the provided movie.sql file (assumed executed externally).

-- Task 3: Write a procedure to find the N movies with the highest rating.
CREATE OR REPLACE PROCEDURE top_n_movies(n IN NUMBER) IS
BEGIN
    FOR rec IN (
        SELECT m.mov_id, m.mov_title, AVG(r.rev_stars) AS avg_rating
        FROM movie m
        JOIN rating r ON m.mov_id = r.mov_id
        GROUP BY m.mov_id, m.mov_title
        ORDER BY avg_rating DESC
        FETCH FIRST n ROWS ONLY
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Movie: ' || rec.mov_title || ' | Rating: ' || rec.avg_rating);
    END LOOP;
END;
/

-- Task 4: Write a function to find the movie status ('Solo' or 'Ensemble').
CREATE OR REPLACE FUNCTION movie_status(movie_title VARCHAR2) RETURN VARCHAR2 IS
    actor_count NUMBER;
    status VARCHAR2(10);
BEGIN
    SELECT COUNT(*) INTO actor_count FROM casts c
    JOIN movie m ON c.mov_id = m.mov_id
    WHERE m.mov_title = movie_title;
    
    IF actor_count = 1 THEN
        status := 'Solo';
    ELSE
        status := 'Ensemble';
    END IF;
    
    RETURN status;
END;
/

-- Task 5: Write a procedure to find possible nominees for the Oscars.
CREATE OR REPLACE PROCEDURE possible_oscar_nominees IS
BEGIN
    FOR rec IN (
        SELECT d.dir_id, d.dir_firstname, d.dir_lastname
        FROM director d
        JOIN direction dr ON d.dir_id = dr.dir_id
        JOIN movie m ON dr.mov_id = m.mov_id
        JOIN rating r ON m.mov_id = r.mov_id
        GROUP BY d.dir_id, d.dir_firstname, d.dir_lastname
        HAVING AVG(r.rev_stars) >= 7 AND COUNT(r.rev_id) > 10
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Director: ' || rec.dir_firstname || ' ' || rec.dir_lastname);
    END LOOP;
END;
/

///c/c/c//cccc/cccc/cC-- Task 1(a): Print your name and student ID.
BEGIN
    DBMS_OUTPUT.PUT_LINE('Name: Your_Name');
    DBMS_OUTPUT.PUT_LINE('Student ID: Your_Student_ID');
END;
/

-- Task 1(b): Take two numbers as input and print their product.
DECLARE
    num1 NUMBER;
    num2 NUMBER;
    product NUMBER;
BEGIN
    num1 := &num1;
    num2 := &num2;
    product := num1 * num2;
    DBMS_OUTPUT.PUT_LINE('Product: ' || product);
END;
/

-- Task 1(c): Take a number as input and print whether it is a whole number or a fraction.
DECLARE
    num NUMBER;
BEGIN
    num := &num;
    IF num = TRUNC(num) THEN
        DBMS_OUTPUT.PUT_LINE('Whole Number');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Fraction');
    END IF;
END;
/

-- Task 2: Execute the provided movie.sql file (assumed executed externally).

-- Task 3: Write a procedure to find the N movies with the highest rating.
CREATE OR REPLACE PROCEDURE top_n_movies(n IN NUMBER) IS
BEGIN
    FOR rec IN (
        SELECT m.mov_id, m.mov_title, AVG(r.rev_stars) AS avg_rating
        FROM movie m
        JOIN rating r ON m.mov_id = r.mov_id
        GROUP BY m.mov_id, m.mov_title
        ORDER BY avg_rating DESC
        FETCH FIRST n ROWS ONLY
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Movie: ' || rec.mov_title || ' | Rating: ' || rec.avg_rating);
    END LOOP;
END;
/

-- Task 4: Write a function to find the movie status ('Solo' or 'Ensemble').
CREATE OR REPLACE FUNCTION movie_status(movie_title VARCHAR2) RETURN VARCHAR2 IS
    actor_count NUMBER;
    status VARCHAR2(10);
BEGIN
    SELECT COUNT(*) INTO actor_count FROM casts c
    JOIN movie m ON c.mov_id = m.mov_id
    WHERE m.mov_title = movie_title;
    
    IF actor_count = 1 THEN
        status := 'Solo';
    ELSE
        status := 'Ensemble';
    END IF;
    
    RETURN status;
END;
/

-- Task 5: Write a procedure to find possible nominees for the Oscars.
CREATE OR REPLACE PROCEDURE possible_oscar_nominees IS
BEGIN
    FOR rec IN (
        SELECT d.dir_id, d.dir_firstname, d.dir_lastname
        FROM director d
        JOIN direction dr ON d.dir_id = dr.dir_id
        JOIN movie m ON dr.mov_id = m.mov_id
        JOIN rating r ON m.mov_id = r.mov_id
        GROUP BY d.dir_id, d.dir_firstname, d.dir_lastname
        HAVING AVG(r.rev_stars) >= 7 AND COUNT(r.rev_id) > 10
    ) LOOP
        DBMS_OUTPUT.PUT_LINE('Director: ' || rec.dir_firstname || ' ' || rec.dir_lastname);
    END LOOP;
END;
/

