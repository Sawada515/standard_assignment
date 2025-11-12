/*
 *  @file 	queue.c
 *  @author 	sawada souta
 *  @date 	2025/11/11 
 *  @brief	値 バッファー用のqueue定義
 *  @note	なんかおかしい気がする
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int init_queue(queue_instance_t *this, int data_length)
{
	if(data_length <= 2) {
		return -1;
	}

	this->data_count = 0;
		
	this->queue_length = data_length;

	this->node = (queue_t*)malloc(sizeof(queue_t) * this->queue_length);
	if(this->node == NULL) {
		return -1;
	}

	this->head = this->node;
	this->tail = &this->node[this->queue_length - 1];

	this->head->next = &this->node[1];
	this->head->prev = this->tail;

	this->tail->next = this->head;
	this->tail->prev = &this->node[this->queue_length - 2];

	this->enqueue_sp = this->head;
	this->dequeue_sp = this->head;

	for(int i = 1; i < this->queue_length - 1; ++i) {
		this->node[i].next = &this->node[i + 1];
		this->node[i].prev = &this->node[i - 1];
	}

	return 0;
}

void enqueue(queue_instance_t *this, double data)
{
	this->enqueue_sp->data = data;

	this->enqueue_sp = this->enqueue_sp->next;

	if(this->data_count < this->queue_length) {
		this->data_count += 1;

	}
	else if(this->data_count == this->queue_length) {
		this->dequeue_sp = this->dequeue_sp->next;
	
	}
	else {
		;
	}
}

double dequeue(queue_instance_t *this)
{
	if(this->data_count <= 0) {
		return 0.0;
	}

	double data = this->dequeue_sp->data;

	this->dequeue_sp->data = 0.0;

	this->dequeue_sp = this->dequeue_sp->next;

	if(this->data_count > 0) {
		this->data_count -= 1;
	}

	return data;
}

void clear_queue(queue_instance_t *this)
{
	queue_t *sp = this->head;

	for(int i = 0; i < this->queue_length; ++i) {
		sp->data = 0.0;

		sp = sp->next;
	}

	this->data_count = 0;
}

void delete_queue(queue_instance_t *this)
{
	free(this->node);

	this->node = NULL;
	this->head = NULL;
	this->tail = NULL;
	this->enqueue_sp = NULL;
	this->dequeue_sp = NULL;

	this->data_count = 0;
}

double get_average(queue_instance_t *this)
{
	double sum = 0.0;
	queue_t *sp = this->dequeue_sp;

	if(this->data_count <= 0) {
		return 0.0;
	}

	for(int i = 0; i < this->data_count; ++i) {
		sum += sp->data;

		sp = sp->next;
	}

	return sum / (double)this->data_count;
}

