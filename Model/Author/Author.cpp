//
// Created by Vladislavs Zimnikovs on 13/10/2020.
//

struct Author {
private:
    int id;
    char name[20]{};
    char surname[20]{};
    int birthYear{};
    int deathYear{};
    char country[20]{};

public:
    int getId() const {
        return id;
    }

    void setName() {
        Author::name[0] = 'f';
    }

    const char* getName() const {
        return name;
    }

    const char* getSurname() const {
        return surname;
    }

    int getBirthYear() const {
        return birthYear;
    }

    void setBirthYear(int birthYear) {
        Author::birthYear = birthYear;
    }

    int getDeathYear() const {
        return deathYear;
    }

    void setDeathYear(int deathYear) {
        Author::deathYear = deathYear;
    }

    const char* getCountry() const {
        return country;
    }
};