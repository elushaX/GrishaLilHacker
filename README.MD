
# Developer side

1. Create application source file in c language![ProgrammSource](images/ProgrammSource.png)

   Here we just check if validation function returns false then we deny access to out application.

   

2. Compile application with no symbol information

   ```bash
   $ gcc app.c -o app
   ```

3. Test your application.

   ![Test](images/Test.png)

# Hacker side

1. Run application with debugger to locate code that blocks us. This is just to localize the problem. In our case we could avoid this step as binary is small in size. (Optional)

   ![Debugging](images/Debugging.png)

   Stepping through code we can see that after the call to the validation function we check if returned value through register named $eax is equal to the value 0x1 (true) then we run our application else we will terminate. This is the issue spot.

   There are several modification we can make, for example using no-op or some other instruction.

   But the simplest solution is just modify the 'test' instruction to invert the logic.

   If the user will enter the correct password the error will occur else we'll pass.

2. Disassemble binary to find address of the issue instruction in the file address space

   ![Disassemble](images/Disassemble.png)

   The 'test' instruction has embedded argument in itself with the value '0x1' that we need to change.

   

3. Change binary so that we avoid login check.

   ![HexEditor](images/HexEditor.png)

   value '0x1' at afdress '000011c2' changed to '0x0'

   ![HexEditor2](images/HexEditor2.png)

4. Done - Sell secret information for some $

   ![Flex](images/Flex.png)
