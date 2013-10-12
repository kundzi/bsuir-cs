﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MySql.Data.MySqlClient;

namespace eBookKeeper.Model
{
  public class MySqlStatements
  {
    public const string TableBooks = "books";
    public const string TableCategories = "categories";
    public const string TableAuthors = "authors";
    public const string TableBook2Author = "book_to_author_map";
    public const string TableBook2Category = "book_to_category_map";

    public const string CreateTables = "CREATE TABLE IF NOT EXISTS bsuir.books (" +
                                       "Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT," +
                                       "Title varchar(255) character set cp1251 DEFAULT 'no name' ," +
                                       "Description TEXT   character set cp1251," +
                                       "Edition TINYINT UNSIGNED DEFAULT 1" +
                                       ");" +

                                       "CREATE TABLE IF NOT EXISTS bsuir.authors (" +
                                       "Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT," +
                                       "Name varchar(255)character set cp1251 DEFAULT 'Какой-то автор.'" +
                                       ");" + 
                                       
                                       "CREATE TABLE IF NOT EXISTS bsuir.categories (" +
	                                     "Id INT UNSIGNED PRIMARY KEY AUTO_INCREMENT," +
	                                     "Name varchar(255) character set cp1251 DEFAULT 'Ниочем'" +
                                       ");";

    public const string CreateMappingTables = "CREATE TABLE IF NOT EXISTS bsuir.book_to_category_map (" +
                                              "BookId INT UNSIGNED NOT NULL," +
                                              "CategoryId INT UNSIGNED NOT NULL," +

                                              "constraint fk_bookId2Category " +
                                              "foreign key (BookId) references bsuir.books(Id)," +
                                              "constraint fk_categoryId2Book " +
                                              "foreign key (CategoryId) references bsuir.categories(Id)" +
                                              ");" +

                                              "CREATE TABLE IF NOT EXISTS bsuir.book_to_author_map (" +
                                              "BookId INT UNSIGNED NOT NULL," +
                                              "AuthorId INT UNSIGNED NOT NULL," +

                                              "constraint fk_bookId2Author " +
                                              "foreign key (BookId) references bsuir.categories(Id)," +
                                              "constraint fk_authorId2Book " +
                                              "foreign key (AuthorId) references bsuir.authors(Id)" +
                                              ");";

    public const string DropTable   = "DROP TABLE IF EXISTS ";

    public const string SelectLastInsertId = "SELECT LAST_INSERT_ID()";
    public const string SelectCountFrom = "SELECT COUNT(*) FROM ";

    // Book stuff
    public static readonly MySqlParameter BookIdParam = new MySqlParameter("@id", MySqlDbType.Int32);
    public static readonly MySqlParameter BookTitleParam = new MySqlParameter("@title", MySqlDbType.VarChar);
    public static readonly MySqlParameter BookDescriptionParam = new MySqlParameter("@descr", MySqlDbType.Text);
    public static readonly MySqlParameter BookEditionParam = new MySqlParameter("@edition", MySqlDbType.UByte);

    public static readonly int BookIdIndex          = 0;
    public static readonly int BookTitleIndex       = 1;
    public static readonly int BookDescriptionIndex = 2;
    public static readonly int BookEditionIndex     = 3;

    public const string BookInsert =
      "INSERT INTO " + TableBooks + " (Title, Description, Edition) values (@title, @descr, @edition)";

    public const string BookUpdate =
      "UPDATE " + TableBooks +" SET Title=@title, Description=@descr, Edition=@edition WHERE Id=@id";

    public const string BookDelete =
      "DELETE FROM " + TableBooks + " WHERE Id=@id";

    public const string BookSelect = 
      "SELECT * FROM " + TableBooks + " ORDER BY Title";

    // Category stuff
    public static readonly MySqlParameter CategoryIdParam = new MySqlParameter("@id", MySqlDbType.Int32);
    public static readonly MySqlParameter CategoryNameParam = new MySqlParameter("@name", MySqlDbType.VarChar);

    // Author stuff
    public static readonly MySqlParameter AuthorIdParam = new MySqlParameter("@id", MySqlDbType.VarChar);
    public static readonly MySqlParameter AuthorNameParam = new MySqlParameter("@name", MySqlDbType.VarChar);
  }
}
