#include "deck.h"

int _strcmp(const char *s1, const char *s2);
char get_value(deck_node_t *card);
void insertion_sort_deck_kind(deck_node_t **deck);
void insertion_sort_deck_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}
/**
 * insertion_sort_deck_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iterate, *insert, *temp;

	for (iterate = (*deck)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->prev;
		while (insert != NULL && insert->card->kind > iterate->card->kind)
		{
			insert->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = insert;
			iterate->prev = insert->prev;
			iterate->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;
			insert->prev = iterate;
			insert = iterate->prev;
		}
	}
}
/**
 * insertion_sort_deck_value - Sort a deck of cards sorted from
 *                             spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iterate, *insert, *temp;

	for (iterate = (*deck)->next; iterate != NULL; iterate = temp)
	{
		temp = iterate->next;
		insert = iterate->next;
		while (insert != NULL &&
			insert->card->kind == iterate->card->kind &&
			get_value(insert) > get_value(iterate))
		{
			insert->next = iterate->next;
			if (iterate->next != NULL)
				iterate->next->prev = insert;
			iterate->prev = insert->prev;
			iterate->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iterate;
			else
				*deck = iterate;
			insert->prev = iterate;
			insert = iterate->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * This function sorts the given deck of cards in two steps:
 * 1. Sorts the cards by their suit (kind) from spades to diamonds.
 * 2. Within each suit, sorts the cards by their value from ace to king.
 *
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */

void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
