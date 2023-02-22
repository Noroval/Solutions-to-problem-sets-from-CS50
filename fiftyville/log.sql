-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking into description to get more info about that day's crime

SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = 'Humphrey Street';

-- Crime took place at 10.15am at Humprey Street bakery. 3 witnesses, all mentioned the bakery. Liitering took place at 16.36, no known witnesses.

-- Look into the transcript

SELECT transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28
AND transcript LIKE '%bakery%';

-- Transcript
-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--  As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

-- Getting the names for license plates (cars) which left crime scenes in our time window.

SELECT name
FROM people, bakery_security_logs
WHERE people.license_plate = bakery_security_logs.license_plate
AND year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;

-- Names are: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey

-- Try to get person names which withdrawned money from ATM that morning

SELECT name
FROM people, bank_accounts, atm_transactions
WHERE atm_transactions.account_number = bank_accounts.account_number
AND bank_accounts.person_id = people.id
AND year = 2021 AND month = 7 AND day = 28
AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

-- Names are; Bruce, Diana, Brooke, Kenny, Iman, Luca, Taylor, Benista
-- Name which matches: Bruce, Diana, Iman, Luca

-- Try to get person names which made phone calls during that day

SELECT name
FROM people, phone_calls
WHERE phone_calls.caller = people.phone_number
AND year = 2021 AND month = 7 AND day = 28 AND name IN ('Bruce', 'Diana', 'Iman', 'Luca');