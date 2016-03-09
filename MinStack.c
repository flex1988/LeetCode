typedef struct {
    int* data;
    int* seq;
    int min;
    int index;
    int seqindex;
} MinStack;

void minStackCreate(MinStack* stack, int maxSize)
{
    stack->data = (int*)calloc(maxSize, sizeof(int));
    stack->seq = (int*)calloc(maxSize, sizeof(int));
    stack->index = 0;
    stack->seqindex = 0;
}

void minStackPush(MinStack* stack, int element)
{
    if (stack->index == 0) {
        stack->min = element;
        stack->seq[stack->seqindex++] = element;
    }
    else {
        if (stack->min >= element) {
            stack->min = element;
            stack->seq[stack->seqindex++] = element;
        }
    }
    stack->data[stack->index++] = element;
}

void minStackPop(MinStack* stack)
{
    int element = stack->data[--stack->index];
    if (element <= stack->min) {
        --stack->seqindex;
        stack->min = stack->seq[stack->seqindex - 1];
    }
}

int minStackTop(MinStack* stack) { return stack->data[stack->index - 1]; }

int minStackGetMin(MinStack* stack) { return stack->min; }

void minStackDestroy(MinStack* stack)
{
    free(stack->data);
    stack = NULL;
}
