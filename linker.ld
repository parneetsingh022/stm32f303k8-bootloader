MEMORY {
  /* starting address and size of the Flash memory */
  FLASH : ORIGIN = 0x08000000, LENGTH = 64K
}

SECTIONS {
  .text : {
    *(.isr_vectors)   /*  vector table at the absolute top */
    *(.text*)
  } > FLASH
}
