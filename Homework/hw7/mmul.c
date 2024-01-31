#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matrix.h"

// Search TODO to find the locations where code needs to be completed

#define     NUM_THREADS     2

typedef struct {
    unsigned int id;
    TMatrix *m, *n, *t;
} thread_arg_t;

static void * thread_main(void * p_arg)
{
    // TODO
    thread_arg_t *my_data = (thread_arg_t*) p_arg;
    unsigned int id = my_data->id;
    TMatrix *m = my_data->m;
    TMatrix *n = my_data->n;
    TMatrix *t = my_data->t;
    int nrows = m->nrows;
    int ncols = n->ncols;

    int start = id*(nrows/2);
    int end = (id+1)*(nrows/2);

    for(int i=start; i<end; i++) {
        for(int j=0; j<ncols; j++) {
            int sum=0;
            for(int k=0; k<m->ncols; k++) {
                sum += m->data[i][k] * n->data[k][j];
            }
            t->data[i][j] = sum;
        }
    }

    return NULL;
}

/* Return the sum of two matrices.
 *
 * If any pthread function fails, report error and exit. 
 * Return NULL if anything else is wrong.
 *
 * Similar to mulMatrix, but with multi-threading.
 */
TMatrix * mulMatrix_thread(TMatrix *m, TMatrix *n)
{
    if (    m == NULL || n == NULL
         || m->ncols != n->nrows )
        return NULL;

    TMatrix * t = newMatrix(m->nrows, n->ncols);
    if (t == NULL)
        return t;

    // TODO
    pthread_t threads[NUM_THREADS];
    thread_arg_t thread_data_array[NUM_THREADS];
    int rc;

    for(int i=0; i<NUM_THREADS; i++) {
        thread_data_array[i].id = i;
        thread_data_array[i].m = m;
        thread_data_array[i].n = n;
        thread_data_array[i].t = t;
        rc = pthread_create(&threads[i], NULL, thread_main, &thread_data_array[i]);
        if(rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for(int i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    return t;
}