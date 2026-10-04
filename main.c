
#define VTOR_REGISTER      (*((volatile unsigned int *) 0xE000ED08))
#define APP_START_ADDRESS  0x08004000


int main(void);

__attribute__((section(".vectors")))
void *vector_table[98] = {
    (void*) 0x20003000, // stack pointer
    (void*) main, // Reset vector
};

void jump_to_application(void) {
    // Firewall the CPU. Disable all hardware interrupts.
    __asm__ volatile("cpsid i");

    // New vector table for the main application.
    VTOR_REGISTER = APP_START_ADDRESS;

    unsigned int app_stack_pointer = (*((volatile unsigned int *) APP_START_ADDRESS));
    unsigned int app_reset_vector  = (*((volatile unsigned int *) (APP_START_ADDRESS + 4)));

    void (*app_entry_point)(void) = (void (*)(void)) app_reset_vector;

    // UPDATE stack-pointer register: MSR MSP APP_STACK_POINTER
    __asm__ volatile("msr msp, %0" : : "r" (app_stack_pointer));

    app_entry_point();}

int main(void) {
    jump_to_application();

    // CPU will never reach here if the jump is successfull.
    while (1) {}
}
