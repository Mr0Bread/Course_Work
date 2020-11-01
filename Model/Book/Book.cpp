//
// Created by Vladislavs Zimnikovs on 13/10/2020.
//

struct BookIdCounter {
private:
    int counter;
public:
    BookIdCounter() {
        BookIdCounter::counter = 0;
    }

    int getNextId() {
        return BookIdCounter::counter++;
    }
};

struct Book {
private:
    int id;
    int publishYear{};
    char title[100]{};
    int authorID{};
    char language[20]{};

public:
    void setTitle(const std::string& title) {
        for (int i = 0; i < title.length(); ++i) {
            Book::title[i] = title[i];
        }
    }

    void setLanguage(const std::string& language) {
        for (int i = 0; i < language.length(); ++i) {
            Book::language[i] = language[i];
        }
    }

    int getId() const {
        return id;
    }

    int getPublishYear() const {
        return publishYear;
    }

    void setPublishYear(int publishYear) {
        Book::publishYear = publishYear;
    }

    const char* getTitle() const {
        return title;
    }

    int getAuthorId() const {
        return authorID;
    }

    void setId(int id) {
        Book::id = id;
    }

    void setAuthorId(int authorId) {
        authorID = authorId;
    }

    const char* getLanguage() const {
        return language;
    }
};
