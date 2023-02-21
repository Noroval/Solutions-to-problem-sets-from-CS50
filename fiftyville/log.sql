-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking into description to get more info about that day's crime

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Crime took place at 10.15am at Humprey Street bakery. 3 witnesses, all mentioned the bakery. Liitering took place at 16.36, no known witnesses.

SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';


SELECT activity, license_plate, minute
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10;
